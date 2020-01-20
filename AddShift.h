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
	/// Сводка для AddShift
	/// </summary>
	public ref class AddShift : public System::Windows::Forms::Form
	{
	public:
		AddShift(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT MAX(ID_shift) FROM Shifts";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (dr->HasRows)
			{
				ID_shift->Text = Convert::ToString(Convert::ToInt32(dr[0]) + 1);
			}
			else
			{
				ID_shift->Text = "1";
			}
			dr->Close();
			connect->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddShift()
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

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  Shift_number;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ID_shift;
	private: System::Windows::Forms::DateTimePicker^  DT_start;
	private: System::Windows::Forms::DateTimePicker^  DT_end;
	public: Form^ general;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	public:
	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddShift::typeid));
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Add_row = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Shift_number = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ID_shift = (gcnew System::Windows::Forms::TextBox());
			this->DT_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->DT_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(197, 229);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 35;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &AddShift::exit_Click);
			// 
			// Add_row
			// 
			this->Add_row->Location = System::Drawing::Point(12, 229);
			this->Add_row->Name = L"Add_row";
			this->Add_row->Size = System::Drawing::Size(115, 23);
			this->Add_row->TabIndex = 34;
			this->Add_row->Text = L"Добавить строку";
			this->Add_row->UseVisualStyleBackColor = true;
			this->Add_row->Click += gcnew System::EventHandler(this, &AddShift::Add_row_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(25, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(173, 13);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Дата и время окончания смены:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(25, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 13);
			this->label3->TabIndex = 29;
			this->label3->Text = L"Дата и время начала смены:";
			// 
			// Shift_number
			// 
			this->Shift_number->Location = System::Drawing::Point(28, 80);
			this->Shift_number->Name = L"Shift_number";
			this->Shift_number->Size = System::Drawing::Size(220, 20);
			this->Shift_number->TabIndex = 28;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(25, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Номер смены:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(25, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"ID смены:";
			this->toolTip1->SetToolTip(this->label1, L"Это поле заполняется автоматически.");
			// 
			// ID_shift
			// 
			this->ID_shift->Location = System::Drawing::Point(28, 31);
			this->ID_shift->Name = L"ID_shift";
			this->ID_shift->ReadOnly = true;
			this->ID_shift->Size = System::Drawing::Size(220, 20);
			this->ID_shift->TabIndex = 24;
			this->toolTip1->SetToolTip(this->ID_shift, L"Это поле заполняется автоматически.");
			// 
			// DT_start
			// 
			this->DT_start->CustomFormat = L"dd.MM.yyyy HH:mm:ss";
			this->DT_start->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->DT_start->Location = System::Drawing::Point(28, 128);
			this->DT_start->Name = L"DT_start";
			this->DT_start->Size = System::Drawing::Size(220, 20);
			this->DT_start->TabIndex = 36;
			this->DT_start->Value = System::DateTime(2019, 5, 11, 13, 57, 46, 0);
			// 
			// DT_end
			// 
			this->DT_end->CustomFormat = L"dd.MM.yyyy HH:mm:ss";
			this->DT_end->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->DT_end->Location = System::Drawing::Point(28, 182);
			this->DT_end->Name = L"DT_end";
			this->DT_end->Size = System::Drawing::Size(220, 20);
			this->DT_end->TabIndex = 37;
			this->DT_end->Value = System::DateTime(2019, 5, 11, 13, 57, 46, 0);
			// 
			// AddShift
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(283, 281);
			this->Controls->Add(this->DT_end);
			this->Controls->Add(this->DT_start);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Add_row);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Shift_number);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ID_shift);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddShift";
			this->Text = L"Добавить смену";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddShift::AddShift_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		general->Enabled = true;
		this->Close();
	}
private: System::Void AddShift_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
private: System::Void Add_row_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (Shift_number->Text != "")
	{
		ChangeLogItem^ ch = gcnew ChangeLogItem("Shifts", "INSERT");
		ch->fill_row_update("Shift_number", this->Shift_number->Text);
		ch->fill_row_update("DT_start", "CONVERT(DATETIME,\'" + this->DT_start->Text + "\',104)");
		ch->fill_row_update("DT_end", "CONVERT(DATETIME,\'" + this->DT_end->Text + "\',104)");
		ch->applyChange();
		MessageBox::Show("Строка успешно добавлена!");
		ID_shift->Text = Convert::ToString(Convert::ToInt32(ID_shift->Text) + 1);
	}
	else
	{
		MessageBox::Show("Ошибка ввода!");
	}
}
};
}
