#pragma once
#include "ChangeLogItem.h"

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для AddShiftOperator
	/// </summary>
	public ref class AddShiftOperator : public System::Windows::Forms::Form
	{
	public:
		AddShiftOperator(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT Operator_number From Operators";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			while (dr->Read())
			{
				this->Operator_number->Items->Add(dr[0]);
			}
			dr->Close();
			command->CommandText = "SELECT ID_shift From Shifts";
			dr = command->ExecuteReader();
			while (dr->Read())
			{
				this->ID_shift->Items->Add(dr[0]);
			}
			dr->Close();
			connect->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddShiftOperator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exit;
	protected:

	private: System::Windows::Forms::Button^  Add_row;
	protected:

	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  ID_shift;
	private: System::Windows::Forms::ComboBox^  Operator_number;


	public: Form^ general;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddShiftOperator::typeid));
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Add_row = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ID_shift = (gcnew System::Windows::Forms::ComboBox());
			this->Operator_number = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(187, 141);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 44;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &AddShiftOperator::exit_Click);
			// 
			// Add_row
			// 
			this->Add_row->Location = System::Drawing::Point(11, 141);
			this->Add_row->Name = L"Add_row";
			this->Add_row->Size = System::Drawing::Size(115, 23);
			this->Add_row->TabIndex = 43;
			this->Add_row->Text = L"Добавить строку";
			this->Add_row->UseVisualStyleBackColor = true;
			this->Add_row->Click += gcnew System::EventHandler(this, &AddShiftOperator::Add_row_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(23, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 13);
			this->label3->TabIndex = 41;
			this->label3->Text = L"Номер оператора:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(23, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 39;
			this->label2->Text = L"ID смены:";
			// 
			// ID_shift
			// 
			this->ID_shift->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ID_shift->Location = System::Drawing::Point(26, 47);
			this->ID_shift->Name = L"ID_shift";
			this->ID_shift->Size = System::Drawing::Size(220, 21);
			this->ID_shift->TabIndex = 46;
			this->ID_shift->SelectionChangeCommitted += gcnew System::EventHandler(this, &AddShiftOperator::ID_shift_SelectionChangeCommitted);
			// 
			// Operator_number
			// 
			this->Operator_number->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Operator_number->Location = System::Drawing::Point(26, 94);
			this->Operator_number->Name = L"Operator_number";
			this->Operator_number->Size = System::Drawing::Size(220, 21);
			this->Operator_number->TabIndex = 47;
			// 
			// AddShiftOperator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(275, 200);
			this->Controls->Add(this->Operator_number);
			this->Controls->Add(this->ID_shift);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Add_row);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddShiftOperator";
			this->Text = L"Добавить оператора смены";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddShiftOperator::AddShiftOperator_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Add_row_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (ID_shift->Text != "" && Operator_number->Text != "")
	{
		ChangeLogItem^ ch = gcnew ChangeLogItem("Shift_operators", "INSERT");
		ch->fill_row_update("ID_shift", this->ID_shift->Text);
		ch->fill_row_update("Operator_number", this->Operator_number->Text);
		ch->applyChange();
		MessageBox::Show("Строка успешно добавлена!");
	}
	else
	{
		MessageBox::Show("Ошибка! Все поля должны быть заполнены!");
	}
}
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
{
	general->Enabled = true;
	this->Close();
}
private: System::Void AddShiftOperator_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	general->Enabled = true;
}
private: System::Void ID_shift_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
{
	this->Operator_number->Items->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT Operator_number FROM Operators WHERE NOT EXISTS (SELECT * FROM Shift_operators "
		+ "WHERE Operators.Operator_number = Shift_operators.Operator_number AND Shift_operators.ID_shift = " + ((ComboBox^)sender)->SelectedItem->ToString() + ")";
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	while (dr->Read())
	{
		this->Operator_number->Items->Add(dr[0]);
	}
	dr->Close();
	connect->Close();
}
};
}
