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
	/// Сводка для AddConnections
	/// </summary>
	public ref class AddConnections : public System::Windows::Forms::Form
	{
	public:
		AddConnections(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT MAX(ID_connection) FROM Connections";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (dr->HasRows)
			{
				ID_connection->Text = Convert::ToString(Convert::ToInt32(dr[0]) + 1);
			}
			else
			{
				ID_connection->Text = "1";
			}
			dr->Close();
			connect->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddConnections()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  ID_connection;

	protected:

	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::DateTimePicker^  T_start;
	private: System::Windows::Forms::DateTimePicker^  T_end;
	public: Form^ general;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolTip^  toolTip1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddConnections::typeid));
			this->ID_connection = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->T_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->T_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// ID_connection
			// 
			this->ID_connection->Location = System::Drawing::Point(28, 47);
			this->ID_connection->Name = L"ID_connection";
			this->ID_connection->ReadOnly = true;
			this->ID_connection->Size = System::Drawing::Size(243, 20);
			this->ID_connection->TabIndex = 0;
			this->toolTip1->SetToolTip(this->ID_connection, L"Это поле заполняется автоматически.");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(25, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"ID соединения:";
			this->toolTip1->SetToolTip(this->label1, L"Это поле заполняется автоматически.");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(25, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Время начала соединения:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(25, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(162, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Время окончания соединения:";
			// 
			// T_start
			// 
			this->T_start->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->T_start->Location = System::Drawing::Point(28, 97);
			this->T_start->Name = L"T_start";
			this->T_start->Size = System::Drawing::Size(243, 20);
			this->T_start->TabIndex = 8;
			this->T_start->Value = System::DateTime(2019, 5, 10, 0, 0, 0, 0);
			// 
			// T_end
			// 
			this->T_end->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->T_end->Location = System::Drawing::Point(28, 146);
			this->T_end->Name = L"T_end";
			this->T_end->Size = System::Drawing::Size(243, 20);
			this->T_end->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 188);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Добавить строку";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddConnections::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(212, 188);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Выйти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddConnections::button2_Click);
			// 
			// AddConnections
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(299, 238);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->T_end);
			this->Controls->Add(this->T_start);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ID_connection);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddConnections";
			this->Text = L"Добавить соединение";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddConnections::AddConnections_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ChangeLogItem^ ch = gcnew ChangeLogItem("Connections", "INSERT");
		ch->fill_row_update("T_start", "CONVERT(TIME,\'" + this->T_start->Text + "\',108)");
		ch->fill_row_update("T_end", "CONVERT(TIME,\'" + this->T_end->Text + "\',108)");
		ch->fill_row_update("Num_of_min", "DATEDIFF(MINUTE, CONVERT(TIME, \'" + this->T_start->Text 
			+ "\',108), CONVERT(TIME, \'" + this->T_end->Text + "\',108))");
		ch->applyChange();
		MessageBox::Show("Строка успешно добавлена!");
		ID_connection->Text = Convert::ToString(Convert::ToInt32(ID_connection->Text) + 1);
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	general->Enabled = true;
	this->Close();
}
private: System::Void AddConnections_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
};
}
